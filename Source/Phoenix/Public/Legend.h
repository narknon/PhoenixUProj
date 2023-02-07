#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Styling/SlateColor.h"
#include "LegendItemData.h"
#include "PhoenixUserWidget.h"
#include "Legend.generated.h"

class ULegendItem;

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API ULegend : public UPhoenixUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftClassPath LegendItemSoftClassPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateColor LegendItemTextColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLegendItemData> LegendItemData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<ULegendItem*> mLegendItems;
    
public:
    ULegend();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveAllLegendItems(int32 StartFromIndex);
    
    UFUNCTION(BlueprintCallable)
    void InitLegendData(const TArray<FLegendItemData> LegendData);
    
    UFUNCTION(BlueprintCallable)
    ULegendItem* GetLegendItem(const int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddLegendItem(const ULegendItem* NewLegendItem);
    
};

