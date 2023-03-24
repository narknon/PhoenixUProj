#include "SocialAIController.h"
#include "Templates/SubclassOf.h"

class UNavigationQueryFilter;

void ASocialAIController::SetRequestedSpeed(float InSpeed) {
}

TEnumAsByte<EPathFollowingRequestResult::Type> ASocialAIController::PlayerMoveToDestination(const FVector& Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPaths) {
    return EPathFollowingRequestResult::Failed;
}

float ASocialAIController::GetRequestedSpeed() const {
    return 0.0f;
}

float ASocialAIController::GetPathDistanceToGoal() const {
    return 0.0f;
}

ASocialAIController::ASocialAIController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

