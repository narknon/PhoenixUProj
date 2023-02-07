#pragma once
#include "CoreMinimal.h"
#include "EForceRenderSettingsScope.h"
#include "ForceRenderSettingsCommand.generated.h"

USTRUCT(BlueprintType)
struct FForceRenderSettingsCommand {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EForceRenderSettingsScope Scope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Command;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisable;
    
    PHOENIX_API FForceRenderSettingsCommand();
};

