#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightGroupWindowMaterialsResources.h"
#include "LightGroupWindowMaterialsVolume.generated.h"

class ULightGroupComponent;

UCLASS(Blueprintable)
class GLOBALLIGHTGROUPS_API ALightGroupWindowMaterialsVolume : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULightGroupComponent* LightGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WindowGroupMaterialParameter;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLightGroupWindowMaterialsResources Resources;
    
public:
    ALightGroupWindowMaterialsVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void RefreshBuildResults();
    
};

