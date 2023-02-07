#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiFX2_NiagraPropertyBase.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class UMultiFX2_NiagraPropertyBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PropertyName;
    
    UMultiFX2_NiagraPropertyBase();
};

