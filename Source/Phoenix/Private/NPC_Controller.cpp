#include "NPC_Controller.h"
#include "CognitionComponent.h"

class UBlackboardComponent;

UBlackboardComponent* ANPC_Controller::GetBlackboard() {
    return NULL;
}

ANPC_Controller::ANPC_Controller() {
    this->CognitionComponent = CreateDefaultSubobject<UCognitionComponent>(TEXT("Cognition"));
}

