#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "PhoenixSceneRigSettings.generated.h"

class UUserWidget;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UPhoenixSceneRigSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> SkipWidgetClass;
    
    UPhoenixSceneRigSettings();
};

