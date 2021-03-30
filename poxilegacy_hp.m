% create legacy C code mex function for Highpass filter
def = legacy_code('initialize');
def.SourceFiles = {'pofilt_hp.c'};
def.HeaderFiles = {'pofilt_hp.h'};
def.SFunctionName = 'ex_sfun_spctrl_hp';
% double pofilt(int reset, double u);
def.OutputFcnSpec = 'double y1 = pofilt_hp(int32 u1, double u2)';
legacy_code('sfcn_cmex_generate', def)
legacy_code('compile', def)
legacy_code('slblock_generate', def)

% create legacy C code mex function for Lowpass filter
def = legacy_code('initialize');
def.SourceFiles = {'pofilt_lp.c'};
def.HeaderFiles = {'pofilt_lp.h'};
def.SFunctionName = 'ex_sfun_spctrl_lp';
% double pofilt(int reset, double u);
def.OutputFcnSpec = 'double y1 = pofilt_lp(int32 u1, double u2)';
legacy_code('sfcn_cmex_generate', def)
legacy_code('compile', def)
legacy_code('slblock_generate', def)
disp('That`s all folks.')