#pragma once
#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "OnItemDragDetectedDelegate.h"
#include "OnItemSelectionChangedDelegate.h"
#include "AkWwiseTreeSelector.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Editor)
class AKAUDIO_API UAkWwiseTreeSelector : public UWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemSelectionChanged OnSelectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemDragDetected OnItemDragged;
    
    UAkWwiseTreeSelector();
};

