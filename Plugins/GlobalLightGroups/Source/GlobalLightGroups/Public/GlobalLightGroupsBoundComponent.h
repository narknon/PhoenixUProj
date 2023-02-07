#pragma once
#include "CoreMinimal.h"
#include "LightGroupBoundComponentSettings.h"
#include "GlobalLightGroupsBoundComponent.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct GLOBALLIGHTGROUPS_API FGlobalLightGroupsBoundComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> ComponentPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightGroupBoundComponentSettings Settings;
    
    FGlobalLightGroupsBoundComponent();
};

