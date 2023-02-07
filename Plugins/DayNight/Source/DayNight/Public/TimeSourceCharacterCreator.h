#pragma once
#include "CoreMinimal.h"
#include "DateInput.h"
#include "TimeSourceVolume.h"
#include "TimeSourceCharacterCreator.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceCharacterCreator : public UTimeSourceVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateInput BaseDate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Time;
    
    UTimeSourceCharacterCreator();
    UFUNCTION(BlueprintCallable)
    static void SetPreviewTime(float globalTime);
    
    UFUNCTION(BlueprintCallable)
    static void PreviewDisabled(bool& Disabled);
    
    UFUNCTION(BlueprintCallable)
    static void GetPreviewTime(float& globalTime);
    
    UFUNCTION(BlueprintCallable)
    void EditorForceUpdate();
    
    UFUNCTION(BlueprintCallable)
    static void DisablePreview();
    
};

