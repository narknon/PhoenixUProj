#pragma once
#include "CoreMinimal.h"
#include "DecalPointLightComponentBase.h"
#include "DecalPointLightInfo.h"
#include "DecalPointLightComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UDecalPointLightComponent : public UDecalPointLightComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDecalPointLightInfo Info;
    
    UDecalPointLightComponent();
    UFUNCTION(BlueprintCallable)
    void SetDecalPointLightInfo(FDecalPointLightInfo NewInfo);
    
};

