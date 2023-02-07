#pragma once
#include "CoreMinimal.h"
#include "InputContextWithType.h"
#include "Engine/DataAsset.h"
#include "ToolRecord.generated.h"

UCLASS(Blueprintable)
class TOOLSET_API UToolRecord : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LookupName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LockName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputContextWithType> Contexts;
    
    UToolRecord();
};

