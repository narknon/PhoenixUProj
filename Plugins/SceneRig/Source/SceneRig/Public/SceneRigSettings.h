#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SceneRigSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class USceneRigSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    float TestValue;
    
    USceneRigSettings();
};

