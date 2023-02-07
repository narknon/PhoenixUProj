#pragma once
#include "CoreMinimal.h"
#include "LegendItemData.h"
#include "Screen.h"
#include "FrontEnd_MenuWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UFrontEnd_MenuWidget : public UScreen {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> LevelNames;
    
    UFrontEnd_MenuWidget();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMenuLegend(const TArray<FLegendItemData>& LegendArray);
    
    UFUNCTION(BlueprintCallable)
    bool ExecuteLoad(const FString& Filename, const int32 CharacterID);
    
};

