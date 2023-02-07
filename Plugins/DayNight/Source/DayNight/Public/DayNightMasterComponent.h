#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CelestialPointOfInterest.h"
#include "DayNightLightRigResults.h"
#include "EphemeralSkyState.h"
#include "EphemerisComputer.h"
#include "SolarNormalizedTime.h"
#include "TimeController.h"
#include "TimeDateSourceStack.h"
#include "DayNightMasterComponent.generated.h"

class ADayNightSky;
class UDayNightLightRig;
class UDayNightMasterComponent;
class UEphemerisBasis;
class UEphemerisSubroutine;
class UGeocentricOrbitsComponent;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class DAYNIGHT_API UDayNightMasterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEphemerisBasis* ForceWorldBasis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeDateSourceStack TimeSourceStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimeController TimeController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UEphemerisSubroutine*> EphemerisProgram;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEphemerisComputer EphemerisComputer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDayNightLightRig* DayNightLightRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEphemeralSkyState SkyState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDayNightLightRigResults DayNightLightRigResults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ADayNightSky* SkyActorOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UGeocentricOrbitsComponent* DebugOrbits;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastNormalizedTime;
    
public:
    UDayNightMasterComponent();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetPointOfInterest(UObject* WorldContextObject, FName Name, FCelestialPointOfInterest& poi);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void GetNightZeroToOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void GetNightZeroDayOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void GetNightNegOneDayOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    void GetDayZeroToOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GetDayNightMaster(UObject* WorldContextObject, UDayNightMasterComponent*& DayNightMaster);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightGetNormalizedTime(UObject* WorldContextObject, FSolarNormalizedTime& CurrentTime, bool& Valid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightGetNightZeroToOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightGetNightZeroDayOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightGetNightNegOneDayOne(UObject* WorldContextObject, float& DayNightValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void DayNightGetDayZeroToOne(UObject* WorldContextObject, float& DayNightValue);
    
};

