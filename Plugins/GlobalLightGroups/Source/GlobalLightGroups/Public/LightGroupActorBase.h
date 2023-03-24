#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface_LightRegionGroup.h"
#include "LightGroupSettings.h"
#include "LightGroupActorBase.generated.h"

UCLASS(Abstract, Blueprintable)
class GLOBALLIGHTGROUPS_API ALightGroupActorBase : public AActor, public IInterface_LightRegionGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightGroupSettings Settings;
    
    ALightGroupActorBase(const FObjectInitializer& ObjectInitializer);
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

