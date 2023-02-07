#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MultiFX2Asset.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable)
class MULTIFX2_API UMultiFX2Asset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    UMultiFX2Asset();
};

