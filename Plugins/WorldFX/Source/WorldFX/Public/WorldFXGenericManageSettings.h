#pragma once
#include "CoreMinimal.h"
#include "WorldFXGenericManageSettings.generated.h"

USTRUCT(BlueprintType)
struct FWorldFXGenericManageSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 flags;
    
    WORLDFX_API FWorldFXGenericManageSettings();
};

