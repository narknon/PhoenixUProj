#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "Templates/SubclassOf.h"
#include "FXAdjustments_FindNearbyTargetInHeirarchy.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_FindNearbyTargetInHeirarchy : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ActorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailIfNotFound;
    
public:
    UFXAdjustments_FindNearbyTargetInHeirarchy();
};

