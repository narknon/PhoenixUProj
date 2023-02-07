#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SelectableSubobjectName.h"
#include "OdcNavLinkComponent.h"
#include "NavSlideInfo.h"
#include "SlideNavLinkComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USlideNavLinkComponent : public UOdcNavLinkComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBottomLinkPosValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SlideBottomLinkEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTopLinkPosValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SlideTopLinkEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableSubobjectName StartLinkComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSelectableSubobjectName EndLinkComponentName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavSlideInfo SlideInfo;
    
public:
    USlideNavLinkComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateNavLink(const FNavSlideInfo& Info);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RegisterNavLink();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidLinks() const;
    
};

