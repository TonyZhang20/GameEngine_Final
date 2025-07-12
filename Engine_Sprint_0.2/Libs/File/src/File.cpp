//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------

#include "File.h"
#include "fileapi.h"

namespace Azul
{
	// holds the directory internally to File.cpp
	static char BaseDir[File::BASE_DIR_SIZE] = {0};

	File::Error File::ClearBaseDir() noexcept
	{
		memset(BaseDir, 0, sizeof(BaseDir));
		return 	Error::SUCCESS;
	}

	File::Error File::GetBaseDir(char *const pDirOut, size_t DirOutSize) noexcept
	{
		if (pDirOut == nullptr)
		{
			return Error::BASE_DIR_NULLPTR_FAIL;
		}

		if (DirOutSize < sizeof(BaseDir))
		{
			return File::Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL;
		}

		memcpy_s(pDirOut, DirOutSize, BaseDir, strlen(BaseDir) + 1);
		return 	Error::SUCCESS;
	}

	File::Error File::SetBaseDir(const char *const pDir) noexcept
	{
		if (pDir == nullptr)
		{
			return File::Error::BASE_DIR_NULLPTR_FAIL;
		}

		if (strlen(pDir) + 1 > sizeof(BaseDir))
		{
			return Error::BASE_DIR_INSUFFICIENT_SPACE_FAIL;
		}

		errno_t err = memcpy_s(BaseDir, sizeof(BaseDir), pDir, strlen(pDir) + 1);

		if (err != 0)
		{
			return File::Error::BASE_DIR_FAIL; 
		}

		return File::Error::SUCCESS;
	}

	bool File::IsHandleValid(File::Handle fh) noexcept
	{
		DWORD flags = 0;
		return GetHandleInformation(fh, &flags) != 0 && fh != INVALID_HANDLE_VALUE;
	}

	File::Error File::Open(File::Handle &fh, const char *const fileName, File::Mode mode, bool UseBaseAddr) noexcept
	{
		char fullPath[256];

		//sprintf_s(fullPath, sizeof(fullPath), "%s\\%s", BaseDir, fileName);

		if (fileName == nullptr)
		{
			return Error::OPEN_FILENAME_FAIL;
		}


		if (UseBaseAddr)
		{
			if (BaseDir[0] == '\0')
			{
				return Error::OPEN_BASE_DIR_FAIL;
			}

			sprintf_s(fullPath, sizeof(fullPath), "%s\\%s", BaseDir, fileName);
		}
		else 
		{
			sprintf_s(fullPath, sizeof(fullPath), "%s", fileName);
		}

		DWORD access = 0;
		DWORD creation = 0;

		switch (mode)
		{
		case Azul::File::Mode::READ:
			access = GENERIC_READ;
			creation = OPEN_EXISTING;
			break;
		case Azul::File::Mode::WRITE:
			access = GENERIC_WRITE;
			creation = CREATE_ALWAYS;
			break;
		case Azul::File::Mode::READ_WRITE:
			access = GENERIC_READ | GENERIC_WRITE;
			creation = OPEN_ALWAYS;
			break;
		default:
			return File::Error::OPEN_FAIL;
			break;
		}

		fh = CreateFile(
			fullPath,
			access,         
			0,
			NULL,          
			creation,   
			FILE_ATTRIBUTE_NORMAL,
			NULL          
		);


		if (!IsHandleValid(fh))
		{
			return Error::OPEN_FAIL;
		}

		return 	Error::SUCCESS;
	}

	File::Error File::Close(File::Handle &fh) noexcept
	{
		if (!IsHandleValid(fh)) return Error::CLOSE_FAIL;

		BOOL close = CloseHandle(fh);

		if (!close) return Error::CLOSE_FAIL;

		fh = INVALID_HANDLE_VALUE;

		return 	Error::SUCCESS;
	}

	File::Error File::Write(File::Handle fh, const void *const buffer, const DWORD inSize) noexcept
	{
		DWORD bytesWritten = 0;
		if (!IsHandleValid(fh) || buffer == nullptr)
		{
			return Error::WRITE_FAIL;
		}

		BOOL result = WriteFile(
			fh,					//File
			buffer,				//ptr
			inSize,				//byte
			&bytesWritten,		//return size
			nullptr				//syn
		);

		if (!result || bytesWritten != inSize) //write part of 
		{
			return Error::WRITE_FAIL;
		}

		return 	Error::SUCCESS;
	}

	File::Error File::Read(File::Handle fh, void *const buffer, const DWORD inSize) noexcept
	{
		if (!IsHandleValid(fh) || buffer == nullptr)
		{
			return Error::READ_FAIL;
		}

		DWORD bytesRead = 0;

		BOOL result = ReadFile(
			fh,     
			buffer,    
			inSize,      
			&bytesRead,  
			nullptr        
		);

		if (!result || bytesRead != inSize)
		{
			return Error::READ_FAIL;
		}

		return Error::SUCCESS;
	}

	File::Error File::Seek(File::Handle fh, File::Position location, int offset) noexcept
	{
		if (!IsHandleValid(fh)) return Error::READ_FAIL;
		
		DWORD moveMethod = 0;
		switch (location)
		{
		case File::Position::BEGIN:
			moveMethod = FILE_BEGIN;
			break;
		case File::Position::CURRENT:
			moveMethod = FILE_CURRENT;
			break;
		case File::Position::END:
			moveMethod = FILE_END;
			break;
		default:
			return Error::SEEK_FAIL;
		}

		DWORD result = SetFilePointer(fh, 
									offset, 
									nullptr, 
									moveMethod);

		if (result == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
		{
			return Error::SEEK_FAIL;
		}

		return 	Error::SUCCESS;
	}

	File::Error File::Tell(File::Handle fh, DWORD &offset) noexcept
	{
		if (!IsHandleValid(fh)) return Error::TELL_FAIL;

		DWORD pos = SetFilePointer(
			fh,
			0,         
			nullptr,    
			FILE_CURRENT
		);

		if (pos == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
		{
			return Error::TELL_FAIL;
		}

		offset = pos;
		return Error::SUCCESS;
	}

	File::Error File::Flush(File::Handle fh) noexcept
	{
		if (!IsHandleValid(fh)) return Error::FLUSH_FAIL;

		BOOL result = FlushFileBuffers(fh);

		if (!result)
		{
			return Error::FLUSH_FAIL;
		}

		return Error::SUCCESS;
	}

}

// --- End of File ---
