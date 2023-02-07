#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "Navigation/PathFollowingComponent.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "SocialAIController.generated.h"

class UNavigationQueryFilter;

UCLASS(Blueprintable)
class SOCIALDISPLAY_API ASocialAIController : public AAIController {
    GENERATED_BODY()
public:
    ASocialAIController();
    UFUNCTION(BlueprintCallable)
    void SetRequestedSpeed(float InSpeed);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EPathFollowingRequestResult::Type> PlayerMoveToDestination(const FVector& Dest, float AcceptanceRadius, bool bStopOnOverlap, bool bUsePathfinding, bool bProjectDestinationToNavigation, bool bCanStrafe, TSubclassOf<UNavigationQueryFilter> FilterClass, bool bAllowPartialPaths);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRequestedSpeed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPathDistanceToGoal() const;
    
};

