#pragma once
#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "CreaturePerchComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCreaturePerchComponent : public UArrowComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBidirectional;
    
public:
    UCreaturePerchComponent();
};

