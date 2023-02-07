#include "AsyncLoadWrapper.h"



void UAsyncLoadWrapper::InstantiateChild() {
}



void UAsyncLoadWrapper::AsyncLoadChildClass(bool InstantiateImmediately) {
}

UAsyncLoadWrapper::UAsyncLoadWrapper() : UUserWidget(FObjectInitializer::Get()) {
    this->IsLoading = false;
    this->ClassIsLoaded = false;
    this->ChildInstantiated = false;
    this->ChildInitialized = false;
    this->ChildWidgetInstance = NULL;
    this->LoadedChildClass = NULL;
}

