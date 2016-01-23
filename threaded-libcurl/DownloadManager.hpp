#pragma once

#include <vector>
#include <string>
#include "Downloader.hpp"

class DownloadManager {
	std::vector<Downloader*> downloaders;
	unsigned int finishedCount = 0, addedCount = 0, failedCount = 0;

	public:
		const static unsigned int version = 0x000300;
		DownloadManager( void );
		~DownloadManager( void );
		double getProgress( void );
		unsigned int addDownload( const char *url, const char *outputFile, const char *expectedHash, const char *expectedEtag );
		int checkDownload( unsigned int i );
		const char* getError( unsigned int i );
		const char* getEtag( unsigned int i );
		void terminate( void );
		void clear( void );
		int busy( void );
		static std::string getFileSHA1( const std::string &filename );
		static std::string getStringSHA1( const std::string &string );
		static bool isInternetConnected();
};
