#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interface_LightRegionGroup.h"
#include "LightGroupSettings.h"
#include "LightGroupComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GLOBALLIGHTGROUPS_API ULightGroupComponent : public UActorComponent, public IInterface_LightRegionGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightGroupSettings Settings;
    
    ULightGroupComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLightRegionGroup(FName& Region, FName& Group);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLightGroupRegion(FName& Region) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLightGroupIndex(int32& GroupNumber);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetLightGroup(FName& Group);
    
    
    // Fix for true pure virtual functions not being implemented
};

