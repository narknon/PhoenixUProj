#pragma once
#include "CoreMinimal.h"
#include "LightComponentMessage.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FLightComponentMessage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsOn;
    
    GLOBALLIGHTGROUPS_API FLightComponentMessage();
};

