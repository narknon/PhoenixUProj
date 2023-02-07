#pragma once
#include "CoreMinimal.h"
#include "MapOnDPadDownDelegate.h"
#include "MapOnDPadLeftDelegate.h"
#include "MapOnDPadRightDelegate.h"
#include "MapOnDPadUpDelegate.h"
#include "MapOnFaceBottomDelegate.h"
#include "MapOnFaceLeftDelegate.h"
#include "MapOnFaceRightDelegate.h"
#include "MapOnFaceTopDelegate.h"
#include "MapScreenBase.h"
#include "HogwartsMapScreen.generated.h"

class UMapHogwarts;

UCLASS(Blueprintable, EditInlineNew)
class UHogwartsMapScreen : public UMapScreenBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnFaceBottom OnMapFaceDown;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnFaceTop OnMapFaceTop;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnFaceRight OnMapFaceRight;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnFaceLeft OnMapFaceLeft;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnDPadDown OnMapDPadDown;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnDPadUp OnMapDPadUp;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnDPadLeft OnMapDPadLeft;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapOnDPadRight OnMapDPadRight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapHogwarts* HogwartsMap;
    
    UHogwartsMapScreen();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowOverlandButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowHogsmeadeButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HogwartsSetPath_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HogwartsSelect_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HogwartsFastTravel_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HogwartsBack_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideOverlandButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideHogsmeadeButton();
    
    UFUNCTION(BlueprintCallable)
    UMapHogwarts* GetMap();
    
};

