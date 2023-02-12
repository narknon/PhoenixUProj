#pragma once
#include "CoreMinimal.h"
#include "AkPluginInfo.generated.h"

USTRUCT(BlueprintType)
struct AKAUDIO_API FAkPluginInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PluginID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString dll;
    
    FAkPluginInfo();
};

