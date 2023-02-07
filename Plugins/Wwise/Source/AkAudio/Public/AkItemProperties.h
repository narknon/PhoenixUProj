#pragma once
#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "OnItemPropertyDragDetectedDelegate.h"
#include "OnItemPropertySelectionChangedDelegate.h"
#include "AkItemProperties.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Editor)
class AKAUDIO_API UAkItemProperties : public UWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemPropertySelectionChanged OnSelectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemPropertyDragDetected OnPropertyDragged;
    
    UAkItemProperties();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void SetSearchText(const FString& newText);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    FString GetSelectedProperty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    FString GetSearchText() const;
    
};

