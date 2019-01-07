#include "googleFileUploadQueue.h"

googleFileUploadQueue::googleFileUploadQueue(QObject *parent) : QObject(parent) {}

googleFileUploadQueue::~googleFileUploadQueue() {}

void
googleFileUploadQueue::slotShouldSendNextFile() {
	
	fileQueue.dequeue(); //file at front of queue has been taken care of
	if (!fileQueue.isEmpty()) {
		emit nextFileToUpload(fileQueue.head());
	}
}

void
googleFileUploadQueue::slotAddFileToQueue(const QString &filePath) {
	fileQueue.enqueue(filePath);
	if (fileQueue.size() == 1) { //queue was previously empty and we can send file for upload right away
		emit nextFileToUpload(filePath);
	}
}

