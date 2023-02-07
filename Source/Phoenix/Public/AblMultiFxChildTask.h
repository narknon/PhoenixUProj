#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblMultiFxChildTask.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FAblMultiFxChildTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ChildName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MultiFXHandleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocationOffset;
    
    PHOENIX_API FAblMultiFxChildTask();
};

