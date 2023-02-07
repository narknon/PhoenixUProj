#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OdcNavLinkComponent.h"
#include "OdcLadderInfo.h"
#include "LadderNavLinkComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULadderNavLinkComponent : public UOdcNavLinkComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBottomLinkPosValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LadderBottomLinkEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTopLinkPosValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LadderTopLinkEnd;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcLadderInfo LadderInfo;
    
public:
    ULadderNavLinkComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateNavLink(const FOdcLadderInfo& Info);
    
protected:
    UFUNCTION(BlueprintCallable)
    void RegisterNavLink();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasValidLinks() const;
    
};

