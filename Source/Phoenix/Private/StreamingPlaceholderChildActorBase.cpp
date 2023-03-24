#include "StreamingPlaceholderChildActorBase.h"

AStreamingPlaceholderChildActorBase::AStreamingPlaceholderChildActorBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StreamingPriority = EStreamingPlaceholderPriority::Normal;
    this->bAutoLoad = true;
    this->bAutoSpawn = true;
    this->ChildActorComponent = NULL;
}

