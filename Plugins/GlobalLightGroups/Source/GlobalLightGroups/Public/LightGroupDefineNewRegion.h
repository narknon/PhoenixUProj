#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "GlobalLightGroupsRegionGroups.h"
#include "Interface_GlobalLightGroupsRegionVolume.h"
#include "LightGroupDefineNewRegion.generated.h"

class ULightOnOffFXList;

UCLASS(Blueprintable)
class GLOBALLIGHTGROUPS_API ALightGroupDefineNewRegion : public AVolume, public IInterface_GlobalLightGroupsRegionVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsRegionGroups RegionGroups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightOnOffFXList* FXList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    ALightGroupDefineNewRegion();
    
    // Fix for true pure virtual functions not being implemented
};

