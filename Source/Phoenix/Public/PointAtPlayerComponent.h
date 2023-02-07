#pragma once
#include "CoreMinimal.h"
#include "PointAtActorBaseComponent.h"
#include "PointAtPlayerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPointAtPlayerComponent : public UPointAtActorBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerIndex;
    
    UPointAtPlayerComponent();
};

