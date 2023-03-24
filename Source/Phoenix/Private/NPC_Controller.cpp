#include "NPC_Controller.h"
#include "CognitionComponent.h"

class UBlackboardComponent;

UBlackboardComponent* ANPC_Controller::GetBlackboard() {
    return NULL;
}

ANPC_Controller::ANPC_Controller(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CognitionComponent = CreateDefaultSubobject<UCognitionComponent>(TEXT("Cognition"));
}

