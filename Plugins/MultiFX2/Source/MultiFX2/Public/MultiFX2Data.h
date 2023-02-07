#pragma once
#include "CoreMinimal.h"
#include "MultiFX2Data.generated.h"

class UMaterialInstanceDynamic;
class UMultiFX2_Base;
class UObject;

USTRUCT(BlueprintType)
struct MULTIFX2_API FMultiFX2Data {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMultiFX2_Base* MultiBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* FXObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialInstanceDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> AdditionalObjectArray;
    
    FMultiFX2Data();
};

