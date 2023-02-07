#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiFX2_NiagraSpawnInfoBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UMultiFX2_NiagraSpawnInfoBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Delay;
    
    UMultiFX2_NiagraSpawnInfoBase();
};

