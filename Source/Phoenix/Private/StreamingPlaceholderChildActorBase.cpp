#include "StreamingPlaceholderChildActorBase.h"

AStreamingPlaceholderChildActorBase::AStreamingPlaceholderChildActorBase() {
    this->StreamingPriority = EStreamingPlaceholderPriority::Normal;
    this->bAutoLoad = true;
    this->bAutoSpawn = true;
    this->ChildActorComponent = NULL;
}

