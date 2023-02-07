#pragma once
#include "CoreMinimal.h"
#include "PhoenixUserWidget.h"
#include "RegionPopuplData.h"
#include "MapRegionInfoWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMapRegionInfoWidget : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UMapRegionInfoWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowBP();
    
    UFUNCTION(BlueprintCallable)
    void Show();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDataBP(const FString& RegionName, const FString& EnemyLevel, int32 MinLevel, int32 MaxLevel, const TArray<FRegionPopuplData>& RegionData);
    
    UFUNCTION(BlueprintCallable)
    void SetData(FString& RegionName, FString& EnemyLevel, int32 MinLevel, int32 MaxLevel, const TArray<FRegionPopuplData>& RegionData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideBP();
    
    UFUNCTION(BlueprintCallable)
    void Hide();
    
};

