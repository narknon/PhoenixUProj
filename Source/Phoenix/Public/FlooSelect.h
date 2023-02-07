#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "Templates/SubclassOf.h"
#include "FlooSelect.generated.h"

class AFloo;
class UUserWidget;
class UVerticalBox;

UCLASS(Blueprintable, EditInlineNew)
class UFlooSelect : public UScreen {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* menuBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFloo* SourceFloo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> Button;
    
    UFlooSelect();
    UFUNCTION(BlueprintCallable)
    void CreateButtonsC();
    
};

