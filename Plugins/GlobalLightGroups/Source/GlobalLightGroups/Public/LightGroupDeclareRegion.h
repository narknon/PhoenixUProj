#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "GlobalLightGroupsRegionName.h"
#include "Interface_GlobalLightGroupsRegionVolume.h"
#include "LightGroupDeclareRegion.generated.h"

class ULightOnOffFXList;

UCLASS(Blueprintable)
class GLOBALLIGHTGROUPS_API ALightGroupDeclareRegion : public AVolume, public IInterface_GlobalLightGroupsRegionVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsRegionName RegionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightOnOffFXList* FXList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    ALightGroupDeclareRegion(const FObjectInitializer& ObjectInitializer);
    
    // Fix for true pure virtual functions not being implemented
};

