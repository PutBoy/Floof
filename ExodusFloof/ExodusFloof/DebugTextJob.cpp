#include "DebugTextJob.h"

DebugTextJob::DebugTextJob(const std::string& text, float x, float y):
	mText(text),
	mX(x),
	mY(y)
{
}

void DebugTextJob::Render()
{
	GetDisplay()->DrawText(mText, mX, mY);
}