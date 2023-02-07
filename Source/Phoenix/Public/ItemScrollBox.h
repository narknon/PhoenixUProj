#pragma once
#include "CoreMinimal.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Components/ScrollBox.h"
#include "ItemScrollBox.generated.h"

UCLASS(Blueprintable)
class UItemScrollBox : public UScrollBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickScrollStepSize;
    
public:
    UItemScrollBox();
    UFUNCTION(BlueprintCallable)
    void SetNavigationScrollPadding(float NewNavigationScrollPadding);
    
    UFUNCTION(BlueprintCallable)
    void SetNavigationDestination(EDescendantScrollDestination NewNavigationDestination);
    
    UFUNCTION(BlueprintCallable)
    void SetAlwaysShowScrollbarTrack(bool NewAlwaysShowScrollbarTrack);
    
    UFUNCTION(BlueprintCallable)
    void OnStickScroll(float AnalogVal);
    
};

