#pragma once
#include "CoreMinimal.h"
#include "ControlMapperPlayerInput.h"
#include "EKeyLayout.h"
#include "OnKeyLayoutChangedDelegate.h"
#include "PhoenixPlayerInput.generated.h"

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UPhoenixPlayerInput : public UControlMapperPlayerInput {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnKeyLayoutChanged OnKeyLayoutChanged;
    
public:
    UPhoenixPlayerInput();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EKeyLayout GetKeyLayout() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceRebuildTransposedKeyMaps(bool bRestoreDefaults, EKeyLayout InCurrentLayout, EKeyLayout InNewLayout);
    
};

