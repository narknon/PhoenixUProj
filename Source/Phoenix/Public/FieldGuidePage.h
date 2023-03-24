#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "FieldGuidePage.generated.h"

UCLASS(Blueprintable)
class AFieldGuidePage : public AActor {
    GENERATED_BODY()
public:
    AFieldGuidePage(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool MoveToNextLocation(const FTransform& DestinationTransform, const float Speed, float DeltaTime);
    
};

