#pragma once
#include "CoreMinimal.h"
#include "MapScreenBase.h"
#include "OverlandMapScreen.generated.h"

class APhoenixMapRegion;
class UMapIcon;
class UMapOverland;

UCLASS(Blueprintable, EditInlineNew)
class UOverlandMapScreen : public UMapScreenBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapOverland* OverlandMap;
    
    UOverlandMapScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RegionChange_Event(APhoenixMapRegion* regionActor, APhoenixMapRegion* subregionActor, bool noString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HoveredFilterRegion_Event(UMapIcon* Icon);
    
    UFUNCTION(BlueprintCallable)
    UMapOverland* GetMap();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitHogwarts_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnterHogwarts_Event();
    
};

