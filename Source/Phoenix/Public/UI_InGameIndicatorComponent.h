#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "UI_InGameIndicatorComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UUI_InGameIndicatorComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PointerIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowPointer;
    
    UUI_InGameIndicatorComponent();
    UFUNCTION(BlueprintCallable)
    void SetShowPointer(bool Show);
    
    UFUNCTION(BlueprintCallable)
    bool GetShowPointer();
    
};

