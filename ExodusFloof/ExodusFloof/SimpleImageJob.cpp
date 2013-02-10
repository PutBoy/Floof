#include "SimpleImageJob.h"

SimpleImageJob::SimpleImageJob(std::string key,float x,float y):mKey(key),mX(x),mY(y){}
SimpleImageJob::~SimpleImageJob(){}

void SimpleImageJob::Render()
{
	GetDisplay()->DrawImage(mKey,mX,mY);
}