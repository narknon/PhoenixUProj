#include "MercunaTask_MoveTo.h"

class AAIController;
class AActor;
class UMercunaTask_MoveTo;

void UMercunaTask_MoveTo::OnMoveComplete(FAIRequestID RequestID, TEnumAsByte<EMercunaMoveResult::Type> Result) {
}

UMercunaTask_MoveTo* UMercunaTask_MoveTo::MercunaMoveTo(AAIController* Controller, FVector GoalLocation, AActor* GoalActor, float EndDistance, bool AcceptPartialPath, bool bLockAILogic) {
    return NULL;
}

UMercunaTask_MoveTo::UMercunaTask_MoveTo() : UAITask(FObjectInitializer::Get()) {
}


