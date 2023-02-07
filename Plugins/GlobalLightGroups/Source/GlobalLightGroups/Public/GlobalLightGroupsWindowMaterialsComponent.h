#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interface_LightRegionGroup.h"
#include "LightGroupSettingsOptional.h"
#include "LightGroupWindowMaterialsResources.h"
#include "GlobalLightGroupsWindowMaterialsComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GLOBALLIGHTGROUPS_API UGlobalLightGroupsWindowMaterialsComponent : public UActorComponent, public IInterface_LightRegionGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightGroupSettingsOptional Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WindowGroupMaterialParameter;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLightGroupWindowMaterialsResources Resources;
    
public:
    UGlobalLightGroupsWindowMaterialsComponent();
    UFUNCTION(BlueprintCallable)
    void RefreshBuildResults();
    
    
    // Fix for true pure virtual functions not being implemented
};

