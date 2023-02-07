#pragma once
#include "CoreMinimal.h"
#include "LightGroupMessage.generated.h"

USTRUCT(BlueprintType)
struct FLightGroupMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOn;
    
    GLOBALLIGHTGROUPS_API FLightGroupMessage();
};

