#pragma once
#include "CoreMinimal.h"
#include "MultiFX2Var.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct MULTIFX2_API FMultiFX2Var {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMultiFX2_Base* FX;
    
    FMultiFX2Var();
};

